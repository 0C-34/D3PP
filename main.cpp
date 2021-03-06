#include <Files.h>
#include <Logger.h>
#include <Block.h>
#include "Rank.h"
#include "Mem.h"
using namespace std;
bool isRunning = false;
void mainLoop();

int main()
{
    Logger::LogAdd("Main", "====== Welcome to D3PP =====", LogType::NORMAL, __FILE__, __LINE__, __FUNCTION__);
    Block b;
    Rank r;

    TaskScheduler::RunSetupTasks();
    isRunning = true;

    char* someMemory = Mem::Allocate(20, "Main.cpp", 15, "Test");
    someMemory[0] = 5;
    someMemory[1] = 10;


    mainLoop();
    Mem::Free(someMemory);
    isRunning = false;
    TaskScheduler::RunTeardownTasks();

    Logger::LogAdd("Module", "Server shutdown complete.", LogType::NORMAL, __FILE__, __LINE__, __FUNCTION__);
    return 0;
}

void mainLoop() {
    while (isRunning) {
        TaskScheduler::RunMainTasks();
       // std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}