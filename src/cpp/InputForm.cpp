// Copyright (c) 2021 Lucas Becker
// STUDENT: Lucas Becker
// PROFESSOR: Eric Grigori
// CLASS: CS-210-T4249 Programming Languages
// TERM: 21EW4
// ASSIGNMENT: Project 2
// FILE: InputForm.cpp

#include "../headers/InputForm.h"

#include <exception>
#include <iostream>
#include <memory>


InputForm::InputForm() {
  std::string header =
      "***************************************\n"
      "************** Data Input *************";
  std::vector<std::string> inputList = {
      "Initial Investment Amount: ", "Monthly Deposit: ", "Annual Interest: ",
      "Number of years: "};
  m_menuHeader = std::make_unique<std::string>(header);
  m_menuOptionsVec = std::make_unique<std::vector<std::string>>(inputList);
}

void InputForm::print() const {
  std::cout << *m_menuHeader << std::endl;
  for (const auto& iter : *m_menuOptionsVec) {
    std::cout << iter << std::endl;
  }
}

std::unique_ptr<UserData> InputForm::getInput() {
  auto userInputMap = std::make_unique<std::map<UserData::Types, double>>();
  double input;

  std::cout << *m_menuHeader << std::endl;

  std::cin.exceptions(std::ios_base::failbit);
  for (int i = 0; i < m_menuOptionsVec->size(); ++i) {
    std::cout << m_menuOptionsVec->at(i);
    std::cin >> input;
    userInputMap->insert_or_assign((UserData::Types)i, input);
  }

  UserData newUserData(std::move(userInputMap));
  return std::make_unique<UserData>(std::move(newUserData));
}

InputForm::InputForm(UserData t_data) {}
