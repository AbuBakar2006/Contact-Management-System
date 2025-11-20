# 📞 Contact Management System

A secure **Console-Based Contact Management Application** implemented in C++. This system allows users to create private accounts to store, manage, and search for personal contacts. It features a login system, input validation for phone numbers, and customizable UI themes.



## 🚀 Features

* **User Authentication:**
    * **Secure Login/Signup:** Users must create an account to access the system.
    * **Credential Storage:** Usernames and passwords are securely stored in `users.txt`.
* **Contact Management (CRUD):**
    * **Add Contact:** Validates that phone numbers contain only digits.
    * **Search:** Find contacts by First Name or Last Name.
    * **Edit:** Update existing contact details.
    * **Delete:** Remove contacts permanently from records.
    * **List:** View all saved contacts in a formatted list.
* **UI Customization:**
    * **Theme Switcher:** Toggle between Light Mode (`color 70`) and Dark Mode (`color 0B`).
* **Data Persistence:**
    * Uses file handling (`fstream`) to ensure data remains saved after the program closes.

## 🛠️ File Handling Structure

The application relies on text files to function as a database:

| File Name | Purpose |
| :--- | :--- |
| **`users.txt`** | Stores registered `Username` and `Password` pairs. |
| **`information.txt`** | Stores `First Name`, `Last Name`, and `Phone Number` of contacts. |
| **`temp.txt`** | A temporary file used during Edit/Delete operations to rewrite data. |

## 💻 How to Run

### 1. Compile
Run the following command in your terminal:

```bash
g++ main.cpp -o contact_saver
```
### 2. Run
Execute the compiled program
```bash
./contact_saver
```
**Note:** This program uses Windows-specific commands like system("cls") and system("color"). It is best run on a Windows machine

### 3. Navigation
The application uses a numeric menu system
```text
LOGIN / SIGNUP


	 1)  Login				 2)  SignUp

	 3)  Change Theme

	 0)  Exit

	-->
```
##📝 Example Usage
#### Scenario: Creating an Account
**Menu Path:** 2) SignUp
```text
Enter a New Username
--> admin

Enter a Password
--> 1234

---Account Created Successfully---
```

#### Scenario: Adding a Contact
**Menu Path:** 2. Add Contact
```text
Enter First Name : John

	Enter Last Name : Doe

	Enter Phone Number : 03001234567

	Contact saved successfully !
```
#### Scenario: Searching for a Contact
**Menu Path:** 1. Search Contact
```text
Enter Name to search : John


		CONTACT DETAILS

First Name : John
Last Name : Doe
Phone Number : 03001234567
```

## ⚠️ Requirements
* **C++ Compiler** (GCC, MinGW, etc.).
* **Operating System:** Windows (Required for UI themes and clear screen commands).
