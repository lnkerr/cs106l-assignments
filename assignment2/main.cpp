/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <sstream>
std::string kYourName = "Crystal Rodgers"; // Don't forget to change this!

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::set<std::string> get_applicants(std::string filename) {
  // STUDENT TODO: Implement this function.
  std::set<std::string> applicants;
  std::ifstream file;
  file.open(filename);
  if (!file.is_open()) {
    std::cerr << "Error opening file: " << filename << std::endl;
    return applicants; // Return empty set if file cannot be opened
  }
  std::string name;
  while (std::getline(file, name)) {
    if (!name.empty()) { // Check if the line is not empty
      applicants.insert(name);
    }
  }
  file.close();
  return applicants;
}

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
std::queue<const std::string*> find_matches(std::string name, std::set<std::string>& students) {
  // STUDENT TODO: Implement this function.
  std::queue<const std::string*> matches;
  std::stringstream ss(name);
  std::string first, last;
  ss>>first >> last; // Split the name into first and last parts
  for(auto& student : students) {
    // Check if the initials match
    std::stringstream it(student);
    std::string student_first, student_last;
    it >> student_first >> student_last; // Split the student's name
    if (student_first[0] == first[0] && student_last[0] == last[0]) {
      matches.push(&student); // Push a pointer to the matching student name
    }
  }
  return matches;
}

/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string*>& matches) {
  // STUDENT TODO: Implement this function.
  if (matches.empty()) {
    return "NO MATCHES FOUND."; // Return this if there are no matches
  }
  // For simplicity, let's just return the first match in the queue
  const std::string* match = matches.front();
  return *match; // Return the match as a string
}

/* #### Please don't remove this line! #### */
#include "autograder/utils.hpp"
