// Copyright © 2021 Lucas Becker

#ifndef SRC_HEADERS_REPORTPRINTER_H_
#define SRC_HEADERS_REPORTPRINTER_H_

#include <memory>
#include <string>

#include "InterestCalc.h"


// DESCRIPTION:
// ReportPrinter takes an InterestCalc and then formats and prints the data as a
// pair of reports. The first report shows the interest data if the user DOES
// NOT make any monthly contributions. The second report shows the interest data
// if the user DOES make monthly contributions to their accounts.
class ReportPrinter {
 public:
  explicit ReportPrinter(std::unique_ptr<InterestCalc> t_calcData);
  void printReports();

 private:
  std::unique_ptr<InterestCalc> m_calcData;
  std::unique_ptr<std::string> m_reportHeaderNoDeposits;
  std::unique_ptr<std::string> m_reportHeaderWithDeposits;
};

#endif  // SRC_HEADERS_REPORTPRINTER_H_
