// Copyright (c) 2021 Lucas Becker
// STUDENT: Lucas Becker
// PROFESSOR: Eric Grigori
// CLASS: CS-210-T4249 Programming Languages
// TERM: 21EW4
// ASSIGNMENT: Project 2
// FILE: UserData.cpp

#include "../headers/UserData.h"

// Default constructor sets data as specified in Airgead specs
UserData::UserData() {
  std::map<UserData::Types, double> t_userData;
  t_userData.emplace(UserData::Types::INIT_INVEST_AMT, -1.0);
  t_userData.emplace(UserData::Types::MONTHLY_DEPOSIT, -1.0);
  t_userData.emplace(UserData::Types::ANNUAL_INTEREST, -1.0);
  t_userData.emplace(UserData::Types::NUM_YEARS, -1.0);
  m_userData = std::make_unique<std::map<UserData::Types, double>>(t_userData);
}

void UserData::setData(
    std::unique_ptr<std::map<UserData::Types, double>> t_userData) {
  m_userData = std::move(t_userData);
}

void UserData::print(UserData::Types dataType) {
  // TODO(Lucas Becker): look into using std::locale to print formatted currency
  std::cout << std::fixed << std::setprecision(2) << std::setw(12) << std::right
            << "$" << m_userData->at(dataType);
}
