// Copyright (c) 2021 Lucas Becker
// STUDENT: Lucas Becker
// PROFESSOR: Eric Grigori
// CLASS: CS-210-T4249 Programming Languages
// TERM: 21EW4
// ASSIGNMENT: Project 2
// FILE: main.cpp

#include <exception>
#include <iostream>
#include <memory>

#include "headers/InputForm.h"
#include "headers/InterestCalc.h"
#include "headers/ReportPrinter.h"

// Enables user to choose whether to loop through again or end the program
bool keepRunning();

int main() {
  bool running = true;
  while (running) {
    try {
      auto inputForm = std::make_unique<InputForm>();
      auto userData = inputForm->getInput();
      auto calcData = std::make_unique<InterestCalc>(std::move(userData));
      auto reportPrinter = std::make_unique<ReportPrinter>(std::move(calcData));
      reportPrinter->printReports();
      running = keepRunning();
    } catch (const std::ios_base::failure& b) {
      std::cout << "Invalid input" << std::endl;
      std::cin.clear();
      std::cin.ignore();
    } catch (const std::exception& e) {
      std::cout << "Error: " << e.what() << std::endl;
    }
  }
  return 0;
}

bool keepRunning() {
  char choice;
  std::cout << "Continue? Enter 'x' to exit program, or anything enter "
               "anything else to continue: ";
  std::cin >> choice;
  if (static_cast<char>(std::tolower(static_cast<int>(choice))) == 'x') {
    return false;
  }
  return true;
}
