// Copyright (c) 2021 Lucas Becker
// STUDENT: Lucas Becker
// PROFESSOR: Eric Grigori
// CLASS: CS-210-T4249 Programming Languages
// TERM: 21EW4
// ASSIGNMENT: Project 2
// FILE: InputForm.h

#ifndef SRC_HEADERS_INPUTFORM_H_
#define SRC_HEADERS_INPUTFORM_H_

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "UserData.h"

// DESCRIPTION:
// The InputForm class encapsulates the user input form, providing the default
// setup provided by Airgead's specs as well as a constructor for custom forms.
// Can print itself with or without creating a new UserData object.
class InputForm {
 public:
  // Constructors
  InputForm();
  explicit InputForm(UserData t_data);
  // Prints input form without capturing any user input
  void print() const;
  // Prints input form, captures user input, creates a new UserData object and
  // returns a std::unique_ptr to it
  std::unique_ptr<UserData> getInput();

 private:
  std::unique_ptr<std::string> m_menuHeader;
  std::unique_ptr<std::vector<std::string>> m_menuOptionsVec;
};

#endif  // SRC_HEADERS_INPUTFORM_H_
