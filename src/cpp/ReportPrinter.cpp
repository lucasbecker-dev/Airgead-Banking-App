// Copyright 2021 Lucas Becker
// STUDENT: Lucas Becker
// PROFESSOR: Eric Grigori
// CLASS: CS-210-T4249 Programming Languages
// TERM: 21EW4
// ASSIGNMENT: Project 2
// FILE: ReportPrinter.cpp

#include "../headers/ReportPrinter.h"

#include <iomanip>
#include <iostream>

ReportPrinter::ReportPrinter(std::unique_ptr<InterestCalc> t_calcData) {
  // Store InterestCalc for later printing
  m_calcData = std::move(t_calcData);

  // Initialize report headers
  std::string tempHeaderNoDeposits =
      "\n"
      "================================================================\n"
      "    Balance and Interest Without Additional Monthly Deposits    \n"
      "================================================================\n"
      "   Year         Year End Balance      Year End Earned Interest  \n"
      "----------------------------------------------------------------\n";
  m_reportHeaderNoDeposits =
      std::make_unique<std::string>(tempHeaderNoDeposits);
  std::string tempHeaderWithDeposits =
      "\n"
      "================================================================\n"
      "     Balance and Interest With Additional Monthly Deposits      \n"
      "================================================================\n"
      "   Year         Year End Balance      Year End Earned Interest  \n"
      "----------------------------------------------------------------\n";
  m_reportHeaderWithDeposits =
      std::make_unique<std::string>(tempHeaderWithDeposits);
}  // ReportPrinter::ReportPrinter(std::unique_ptr<InterestCalc> t_calcData)

void ReportPrinter::printReports() {
  // Print header and data for first report without monthly deposits
  std::cout << *m_reportHeaderNoDeposits;
  for (auto iter : m_calcData->getDataWithoutDeposits()) {
    std::cout.width(7);
    std::cout << std::right << std::setfill(' ') << std::to_string(iter.m_year);
    std::cout << std::setw(29 - std::to_string(iter.m_yearEndBalance).length())
              << std::right << std::fixed << std::setprecision(2)
              << std::setfill('.') << "$" << iter.m_yearEndBalance;
    std::cout << std::setw(
                     34 - std::to_string(iter.m_yearEndEarnedInterest).length())
              << std::right << std::fixed << std::setprecision(2)
              << std::setfill('.') << "$" << iter.m_yearEndEarnedInterest;
    std::cout << std::endl;
  }

  // Print header and data for second report with monthly deposits
  std::cout << *m_reportHeaderWithDeposits;
  for (auto iter : m_calcData->getDataWithDeposits()) {
    std::cout.width(7);
    std::cout << std::right << std::setfill(' ') << std::to_string(iter.m_year);
    std::cout << std::setw(29 - std::to_string(iter.m_yearEndBalance).length())
              << std::right << std::fixed << std::setprecision(2)
              << std::setfill('.') << "$" << iter.m_yearEndBalance;
    std::cout << std::setw(
                     34 - std::to_string(iter.m_yearEndEarnedInterest).length())
              << std::right << std::fixed << std::setprecision(2)
              << std::setfill('.') << "$" << iter.m_yearEndEarnedInterest;
    std::cout << std::endl;
  }
}  // void ReportPrinter::printReports()
