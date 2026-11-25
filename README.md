# DSA-Basic-Project-Question-Management-System-MCQ-Type-
ONLINE EXAM QUESTION MANAGEMENT SYSTEM

# 1. Project Overview
The Online Exam Question Management System is a standalone, offline, menu-driven console application developed using core Data Structures and Algorithms (DSA). Rather than a live website or web-hosted portal, this system runs locally in a command-line/terminal environment to model the core logic of an automated MCQ examination system. It divides operations into two distinct console roles—Admin and Student—allowing the Admin to dynamically create subjects and manage MCQ banks in memory, while enabling Students to attempt tests on those subjects and receive instant calculated results.

# 2. Core Objectives
- Offline Console Execution: Build a fast, lightweight, terminal-based application without relying on web servers or external internet connectivity.
- Dynamic Subject Management: Allow the Admin to create and manage subjects at runtime instead of using hardcoded subject lists.
- Structured MCQ Handling: Implement complete Create, Read, Update, and Delete (CRUD) operations for multiple-choice questions.
- Automated Evaluation: Automatically compare student inputs against stored answer keys in real time to generate instant scores.

# 3. System Modules & Functionalities

A. Admin Module (Complete Subject & Question Control)
- Admin Login: Password-protected console access so only authorized users can modify subjects and questions.
- Dynamic Subject Creation: Add, rename, or remove subjects dynamically during execution. Every subject displayed to students comes directly from the list created by the Admin.
- Add MCQ Questions: Insert new multiple-choice questions under any Admin-created subject, storing the question statement, four options (A, B, C, D), and the correct answer key.
- Update & Delete Questions: Search existing records by Question ID or subject name to modify question text, change options, or delete outdated questions.
- View Question Bank: Display all stored subjects and their corresponding MCQs with answer keys directly in the console.

B. Student Module (Exam Attempt & Instant Scoring)
- Student Entry: Accept student details (Name and Roll Number) in the terminal before starting an exam session.
- Dynamic Subject Selection: Display all subjects created by the Admin so the student can pick which subject test to attempt.
- Sequential MCQ Test: Present the selected subject's MCQs one by one in the console and record the student's chosen option (A, B, C, or D) for each question.
- Instant Result Summary: Immediately evaluate responses after the final question and display total questions, correct answers, incorrect answers, and overall percentage.

# 4. Data Structures & Algorithms Applied
- Structures (struct) / Classes: Used to bundle MCQ attributes (Question ID, Subject Name, Question Text, Options A–D, Correct Option) and Student session records into single logical units.
- Linked Lists / Dynamic Arrays: Used to store subjects and MCQs dynamically in memory, allowing unlimited additions and deletions at runtime without fixed array size constraints.
- Searching Algorithms: Used to filter MCQs belonging to a specific Admin-created subject and locate individual questions by ID during updates or deletions.
- Sequential Traversal: Used to iterate through the question list step by step during an active student exam session.
- Local File Handling (Optional): Used to save subjects and MCQs in local .txt or .dat files so data persists on the computer even after the terminal closes.

# 5. Project Outcome
The Online Exam Question Management System demonstrates practical mastery of core Data Structures and Algorithms by turning abstract concepts—such as dynamic memory allocation, linked structures, searching, and traversal—into a complete, working, menu-driven command-line application.
# https://www.linkedin.com/in/vinay-kumar-162164386/
