// Author: Yash Deshpande
// Date  : 07-10-2026
// Position: Darwin Runtime Engineer, Core OS
// Interviewers: Dominic Chen, Rokhini Prabhu

// Please fill in the TODOs
typedef struct {
  int active_readers; 
  int active_writers; 
  int waiting_writers;
  // sem_t binarySem; 
  // sem_t semW;  
  mutex m;
  cond_var cv;
} rw_lock_t;

int rw_lock_init(rw_lock_t *R)
{
  // TODO
  R->cnt_readers = 0;
  active_writers = 0;
  waiting_writers = 0;
  sem_init(&binarySem, 1);
  // init
  mutex_init(&);
  cond_var_init(&cv);
}

int rw_lock_read_lock(rw_lock_t *R)
{
  // TODO
  m.lock()
  
  while(waiting_writers > 0  || active_writers == 1) {
    cond_wait();
  }
  active_readers++;
  m.unlock();
}

int rw_lock_read_unlock(rw_lock_t *R)
{
  // TODO
  m.lock()
  active_readers--;
  if(active_readers == 0) {
    cond_broadcast();
  }
  m.unlock();
}

int rw_lock_write_lock(rw_lock_t *R)
{
  // TODO
  m.lock();
  while(active_writers == 1 || active_readers > 0) {
    cond_wait();
  }
  active_writers = 1;
  m.unlock()
}

int rw_lock_write_unlock(rw_lock_t *R)
{
  // TODO
  m.lock()
  active_writers = 0;
  cond_broadcost;
  m.unlock();
}

/*

####################################################### Claude Answers #######################################################

Q1) I initially tried the  reader-preferring version with semaphores, but the interviewer didn't like my strategy to sleep on the 
mutex when a reader comes in after a writer.

The classic semaphore version has a structural problem, so the interviewer's objection was probably to the design rather 
than your code. In it, the first reader calls sem_wait(wrt) while still holding the counter mutex. If a writer is active, 
that reader goes to sleep holding the mutex, and every later reader then piles up blocked on the mutex too. Sleeping while 
holding a lock makes the mutex a second, accidental wait queue.

For a Darwin Core OS role, the bigger issue is likely priority inversion. A semaphore has no owner: the last reader to 
leave releases wrt, and that may not be the thread that acquired it. The kernel can't tell which thread to boost, so a 
high-priority writer waiting on wrt can't donate its priority to the low-priority readers it's waiting on. XNU's turnstiles 
exist to handle exactly that, and mutex-plus-condvar designs keep ownership clear.

The condvar version fixes both problems. You only ever hold the mutex briefly to check and update state, and all real waiting 
happens in cond_wait, which releases the mutex while you sleep. That's the version you ended up writing, and it's the one they 
wanted.

*/