// Author : Yash Deshpande
// Date   : 27-09-2025
// Tutor  : Keerti Purswani

#include <iostream>
#include <string>
using namespace std;

// Builder Design Pattern has 4 parts
// 1. Product
// 2. Builder
// 3. Concrete Builder
// 4. Director

// ###############
// Product
// ############### 
class Desktop {
    string monitor;
    string keyboard;
    string mouse;
    string speaker;
    string ram;
    string motherboard;
    string processor;

    public:
        void setMonitor(string pMonitor){
            monitor = pMonitor;
        }
        void setKeyboard(string pKeyboard){
            keyboard = pKeyboard;
        }
        void setMouse(string pMouse){
            mouse = pMouse;
        }
        void setSpeaker(string pSpeaker){
            speaker = pSpeaker;
        }
        void setRam(string pRam){
            ram = pRam;
        }
        void setMotherboard(string pMotherboard){
            motherboard = pMotherboard;
        }
        void setProcessor(string pProcessor){
            processor = pProcessor;
        }
        void showSpecs() {
            cout << "----------------------------------------------------------------- " << endl;
            cout << "Monitor = " << monitor << endl;
            cout << "Keyboard =" << keyboard << endl;
            cout << "Mouse = " << mouse<< endl;
            cout << "Speaker = " << speaker<< endl;
            cout << "Ram = " << ram << endl;
            cout << "Processor = " << processor << endl;
            cout << "Motherboard = " << motherboard << endl;
            cout << "----------------------------------------------------------------- " << endl;
        }
};

// ###############
// Builder
// ###############
class DesktopBuilder {
    protected:
        Desktop *desktop;

    public:
        DesktopBuilder() {
            desktop = new Desktop;
        }

        virtual void buildMonitor() = 0;
        virtual void buildKeyboard() = 0;
        virtual void buildMouse() = 0;
        virtual void buildSpeaker() = 0;
        virtual void buildRam() = 0;
        virtual void buildProcessor() = 0;
        virtual void buildMotherboard() = 0;
        
        virtual Desktop* getDesktop() {
            return desktop;
        }
};

// ###############
// Concrete Builder
// ###############
class DellDesktopBuilder : public DesktopBuilder {
    // this is where the Desktop would be configured.

    void buildMonitor() {
        desktop->setMonitor("Dell Monitor");
    }
    void buildKeyboard() {
        desktop->setKeyboard("Dell Keyboard");
    }
    void buildMouse() {
        desktop->setMouse("Dell Mouse");
    }
    void buildSpeaker() {
        desktop->setSpeaker("Dell Speaker");
    }
    void buildRam() {
        desktop->setRam("Dell Ram");
    }
    void buildProcessor() {
        desktop->setProcessor("Dell Processor");
    }
    void buildMotherboard() {
        desktop->setMotherboard("Dell Motherboard");
    }
};

class HPDesktopBuilder : public DesktopBuilder {
    // this is where the Desktop would be configured.

    void buildMonitor() {
        desktop->setMonitor("HP Monitor");
    }
    void buildKeyboard() {
        desktop->setKeyboard("HP Keyboard");
    }
    void buildMouse() {
        desktop->setMouse("HP Mouse");
    }
    void buildSpeaker() {
        desktop->setSpeaker("HP Speaker");
    }
    void buildRam() {
        desktop->setRam("HP Ram");
    }
    void buildProcessor() {
        desktop->setProcessor("HP Processor");
    }
    void buildMotherboard() {
        desktop->setMotherboard("HP Motherboard");
    }
};


// ###############
// Director
// ###############
class DesktopDirector {
private:
    DesktopBuilder * desktopBuilder;

public:
    DesktopDirector(DesktopBuilder* pDesktopBuilder) {
        desktopBuilder = pDesktopBuilder;
    }

    Desktop* BuildDesktop() {
        desktopBuilder->buildKeyboard();
        desktopBuilder->buildMonitor();
        desktopBuilder->buildMouse();
        desktopBuilder->buildSpeaker();
        desktopBuilder->buildRam();
        desktopBuilder->buildProcessor();
        desktopBuilder->buildMotherboard();
        return desktopBuilder->getDesktop();
    }

    // You can return Desktop this way too.
    // Desktop* getDesktop() {
    //     return desktopBuilder->getDesktop();
    // }
};

int main() {
    // Sometimes we can also combine the director into the client inside the main

    HPDesktopBuilder* hpDesktopBuilder = new HPDesktopBuilder();
    DellDesktopBuilder* dellDesktopBuilder = new DellDesktopBuilder();

    DesktopDirector* director1 = new DesktopDirector(hpDesktopBuilder);
    DesktopDirector* director2 = new DesktopDirector(dellDesktopBuilder);

    Desktop* desktop1 = director1->BuildDesktop();
    Desktop* desktop2 = director2->BuildDesktop();

    desktop1->showSpecs();
    desktop2->showSpecs();

    return 0;
}