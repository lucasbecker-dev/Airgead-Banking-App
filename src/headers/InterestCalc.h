// Copyright (c) 2021 Lucas Becker
// STUDENT: Lucas Becker
// PROFESSOR: Eric Grigori
// CLASS: CS-210-T4249 Programming Languages
// TERM: 21EW4
// ASSIGNMENT: Project 2
// FILE: InterestCalc.h

#ifndef SRC_HEADERS_INTERESTCALC_H_
#define SRC_HEADERS_INTERESTCALC_H_

#include <memory>
#include <vector>

#include "UserData.h"

// DESCRIPTION:
// InterestCalc calculates, stores, and provides access to compound interest
// data derived from user input.
class InterestCalc {
  // internal struct for easier data storage
  struct CalcData {
    int m_year;
    double m_yearEndBalance;
    double m_yearEndEarnedInterest;
  };

 public:
  // Calculations are made in the constructor, just instantiate the object and
  // then use the getters to see results
  explicit InterestCalc(std::unique_ptr<UserData> t_userData);
  // Gets internal userData object if needed;
  UserData &getUserData() const;
  // Gets calculated data if user DID make additional monthly deposits to their
  // account
  std::vector<CalcData> &getDataWithDeposits() const;
  // Gets calculated data if user DID NOT make additional monthly deposits to
  // their account
  std::vector<CalcData> &getDataWithoutDeposits() const;

 private:
  std::unique_ptr<UserData> m_userData;
  std::unique_ptr<std::vector<CalcData>> m_calcWithMonthlyDeposits;
  std::unique_ptr<std::vector<CalcData>> m_calcWithoutMonthlyDeposits;
};

#endif  // SRC_HEADERS_INTERESTCALC_H_
