// Copyright © 2021 Lucas Becker

#ifndef SRC_HEADERS_USERDATA_H_
#define SRC_HEADERS_USERDATA_H_

#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <utility>

// DESCRIPTION:
// The UserData class encapsulates a std::unique_ptr to a std::map, defining key
// values for it, functionality for mapping data to it, and functionality for
// printing its contents.
class UserData {
 public:
  // enum to avoid error-prone nature of passing strings
  enum Types {
    INIT_INVEST_AMT = 0,
    MONTHLY_DEPOSIT = 1,
    ANNUAL_INTEREST = 2,
    NUM_YEARS = 3
  };
  // Constructors
  UserData();
  explicit UserData(
      std::unique_ptr<std::map<UserData::Types, double>> t_userData)
      : m_userData(std::move(t_userData)) {}
  // Setter
  void setData(std::unique_ptr<std::map<UserData::Types, double>> t_userData);
  // Getter
  std::unique_ptr<std::map<UserData::Types, double>> getData() {
    return std::move(m_userData);
  }
  // Formats and prints the specified piece of user data
  void print(UserData::Types dataType);

 private:
  std::unique_ptr<std::map<UserData::Types, double>> m_userData;
};

#endif  // SRC_HEADERS_USERDATA_H_
