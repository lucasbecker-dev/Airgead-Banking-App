// Copyright (c) 2021 Lucas Becker
// STUDENT: Lucas Becker
// PROFESSOR: Eric Grigori
// CLASS: CS-210-T4249 Programming Languages
// TERM: 21EW4
// ASSIGNMENT: Project 2
// FILE: InterestCalc.cpp

#include "../headers/InterestCalc.h"

InterestCalc::InterestCalc(std::unique_ptr<UserData> t_userData) {
  // getting data from UserData and setting up data structures to hold
  // calculated data
  m_userData = std::move(t_userData);
  auto tempPtr = std::make_unique<std::map<UserData::Types, double>>();
  tempPtr = m_userData->getData();
  auto tempVecNoDeposits = std::vector<InterestCalc::CalcData>();
  auto tempVecWithDeposits = std::vector<InterestCalc::CalcData>();

  // local data for keeping track of interest calculations
  int curYear = 1;
  double curYearEndBalance = tempPtr->at(UserData::Types::INIT_INVEST_AMT);
  double curYearEndEarnedInterest =
      curYearEndBalance *
      (tempPtr->at(UserData::Types::ANNUAL_INTEREST) / 100.0);
  curYearEndBalance += curYearEndEarnedInterest;

  // calculations for interest when no additional monthly deposits are made
  for (int i = 0; i < tempPtr->at(UserData::Types::NUM_YEARS); ++i) {
    auto newData = std::make_unique<CalcData>();
    newData->m_year = curYear;
    newData->m_yearEndBalance = curYearEndBalance;
    newData->m_yearEndEarnedInterest = curYearEndEarnedInterest;
    tempVecNoDeposits.push_back(*newData);
    ++curYear;
    curYearEndEarnedInterest +=
        curYearEndBalance *
        (tempPtr->at(UserData::Types::ANNUAL_INTEREST) / 100.0);
    curYearEndBalance += curYearEndEarnedInterest;
  }

  // resetting local data for next set of calculations
  curYear = 1;
  curYearEndBalance = tempPtr->at(UserData::Types::INIT_INVEST_AMT) +
                      (tempPtr->at(UserData::Types::MONTHLY_DEPOSIT) * 12);
  curYearEndEarnedInterest =
      curYearEndBalance *
      (tempPtr->at(UserData::Types::ANNUAL_INTEREST) / 100.0);
  curYearEndBalance += curYearEndEarnedInterest;

  // calculations for interest when additional monthly deposits are made
  for (int i = 0; i < tempPtr->at(UserData::Types::NUM_YEARS); ++i) {
    auto newData = std::make_unique<CalcData>();
    newData->m_year = curYear;
    newData->m_yearEndBalance = curYearEndBalance;
    newData->m_yearEndEarnedInterest = curYearEndEarnedInterest;
    tempVecWithDeposits.push_back(*newData);
    ++curYear;
    curYearEndBalance += tempPtr->at(UserData::Types::MONTHLY_DEPOSIT) * 12;
    curYearEndEarnedInterest +=
        curYearEndBalance *
        (tempPtr->at(UserData::Types::ANNUAL_INTEREST) / 100.0);
    curYearEndBalance += curYearEndEarnedInterest;
  }

  // store pointers to vectors with calculated data
  m_calcWithMonthlyDeposits =
      std::make_unique<std::vector<CalcData>>(tempVecWithDeposits);
  m_calcWithoutMonthlyDeposits =
      std::make_unique<std::vector<CalcData>>(tempVecNoDeposits);
}  // END OF InterestCalc::InterestCalc(std::unique_ptr<UserData> t_userData)

UserData &InterestCalc::getUserData() const { return *m_userData; }

std::vector<InterestCalc::CalcData> &InterestCalc::getDataWithDeposits() const {
  return *m_calcWithMonthlyDeposits;
}

std::vector<InterestCalc::CalcData> &InterestCalc::getDataWithoutDeposits()
    const {
  return *m_calcWithoutMonthlyDeposits;
}
