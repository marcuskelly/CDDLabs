/*!
@author Mark Kelly
@date 02/10/17
@version 1.0
*/
#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <string>


int shared_Int = 0;

void taskOne(std::shared_ptr<Semaphore> mutex){
  
  mutex->Wait();
  shared_Int++;
  std::cout << "threadA --- shared_Int : " +  std::to_string(shared_Int) <<std::endl;
  mutex->Signal(); 
}
void taskTwo(std::shared_ptr<Semaphore> mutex){
 
  mutex->Wait();
  shared_Int++;
  std::cout << "threadB --- shared_Int : " + std::to_string(shared_Int) <<std::endl;
  mutex->Signal();
}

void taskThree(std::shared_ptr<Semaphore> mutex){
  
  mutex->Wait();
  shared_Int++;
   std::cout << "threadC --- shared_Int : " + std::to_string(shared_Int) <<std::endl;
  mutex->Signal(); 
}

void taskFour(std::shared_ptr<Semaphore> mutex){
  
  mutex->Wait();
  shared_Int++;
  std::cout << "threadD --- shared_Int : " + std::to_string(shared_Int) <<std::endl;
  mutex->Signal(); 
}

int main(void){
  
  std::thread threadA, threadB, threadC, threadD;
  std::shared_ptr<Semaphore> mutex( new Semaphore);
 
  
  /*< Launch the threads  */
  /*We do not care which thread executes first (schedular decides), each task will then hold onto sharedInt, ++, then release it  */
  threadA=std::thread(taskOne,mutex);
  threadB=std::thread(taskTwo,mutex);
  threadC=std::thread(taskThree,mutex);
  threadD=std::thread(taskFour,mutex);
  
  
  std::cout << "Launched from the main\n";
  threadA.join();
  threadB.join();
  threadC.join();
  threadD.join();
  return 0;
}
