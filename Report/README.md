# INTERNET BANKING SYSTEM
- **In this project user can do all the banking activites like real bank. this file contains the requirements of the user and collection of analysis.**
## This application can Do Following Activities
- Account Registration
- Account Login
- Deposit Cash
- Withdraw Cash
- Show Reward Points
- Change Passcode
- Foreign Exchange


_____________________
# Requirements

_________________________________________________________
# Indroduction

_________________________________________________________
Internet-Banking Application 
- In this project user can do all the banking activites like real bank. this file contains the requirements of the user and collection of analysis.

# SWOT ANALYSIS
_________________________________________________________

![enter image description here](https://www.linkpicture.com/q/DATAFLOW-5.png)

**Strength**-- User can perform the following activities:

- Balance enquiry
- Deposit cash
- Cash withdrawal
- Online transfer
- Earn Reward Points
- Show Reward Points 
- Password change

**Weakness**-- User Need correct password to further activity.

**Opportunity**-- User can check balance ,Withdraw ,Deposit cash and Change password.

**Threats**-- If Password is lost User will loose the account

# 4W's and 1H

__________________________________________________________
![enter image description here](https://www.linkpicture.com/q/DATAFLOW-2.png)

### Who:
__________________________________________________________
**All the banking customers can use the Internet Banking system who wants to do the banking activities Remotely.**
### What:
__________________________________________________________
**Internet banking sytem is built to do all the banking activity in one application.**

### When:
__________________________________________________________
**It can be used whenever the user needs the banking activity to be done.**
### Where:
__________________________________________________________
**User can access this application with any one of the c program compiler.**
### How:
__________________________________________________________
**Implemented  using c language.**

# Detailed requirements
__________________________________________________________
#### High level requirements:
__________________________________________________________
| Id | Description | Status |
| ------ | ------ | ------ |
| HLR1|The system can do balance Enquiry|Implemented||
| HLR2|User can deposit cash|Implemented|
| HLR3|User can wiothdraw cash|Implemented|
| HLR4|User can transfer cash|Implemented|
| HLR5|User can change Password|Implemented|
|HLR6|user can View their Reward Points|Implemented|

#### Low level requirements:
__________________________________________________________
| Id | Description | Status |
| ------ | ------ | ------ |
| LLR1|User can do transaction if the user has registered the account |Implemented||
| LLR2|User can able register their account|Implemented|
| LLR3|User can able to lodin with phone number|Implemented|
__________________________________________________________
# HIGH LEVEL DESIGN

## Use Case Diagram
![enter image description here](https://www.linkpicture.com/q/Untitled-Workspace.png)


# LOW LEVEL DIAGRAM

##  Activity Diagram

![enter image description here](https://www.linkpicture.com/q/Untitled-Workspace-4.png)
﻿# HIGH LEVEL DIAGRAM
### ARCHITECTURE DIAGRAM
___________________

![enter image description here](https://www.linkpicture.com/q/Untitled-Workspace-5.png)

# LOW LEVEL DIAGRAM
### DATA FLOW DIAGRAM
______________________

![enter image description here](https://www.linkpicture.com/q/DATAFLOW-7.png)
______________
# SOURCE CODE
[MAIN.c](https://github.com/Abishek1027/m1-projectgoal-utility/blob/main/3_Implementation/Implementation_main_c.c)

# TEST PLAN:
### TABLE : High Level Test Plan 
___ 
|Test Id  | Description |Exp I/P  |Exp O/P  |Act O/P  |Test Type  |
|--|--|--|--|--|--|
| HLR1 |Registration of new account|Account number:123456 ,Phone no:8072334574 ,Password: 12345|User Registration Successfull|User Registration Successfull|Requirement based|
|HLR2|Existing user|Phone no:8072334574 ,Password:12345|Welcome 123456|Welcome 123456|Requirement based|
|HLR3|Deposit Cash|Enter Deposit Amount:5000|Deposited Successfully|Deposited Successfully|Requirement Baesd|
|HLR4|Withdraw cash|Enter Amount: 2000|You have withdrawn: 2000|You have withdrawn :2000|Requirement Based|
|HLR5|Balance check|Enter your option: 1|your current balance is :3000|your current balance is :3000|Requirement Based|
|HLR6|Wrong Password|4569874|Password|Password|Boundary Based|
|HLR7|Entering Password|123456|Password Match|Password Match|Boundary Based|
____________________________
### Table : Low Level Test Plan
______________________
|Test Id  | Description |Exp I/P  |Exp O/P  |Act O/P  |Test Type  |
|--|--|--|--|--|--|
| LLR1 |Wrong Account number|000000|Invalid Account number|Invalid Account number|Requirement based|
|LLR2|Wrong Choice|7|Invalid Choice|Exit|Scenario Based
____________________
# ALL THE COMPILATION OUTPUTS ARE ATTACHED HERE

# OUTPUT IMAGES
### 1. ACCOUNT REGISTRATION OR LOGIN

![enter image description here](https://www.linkpicture.com/q/WhatsApp-Image-2022-02-11-at-16.24.27.jpeg)


### 2. ACCOUNT REGISTRATION
___________________________ 
![enter image description here](https://www.linkpicture.com/q/WhatsApp-Image-2022-02-11-at-16.26.56.jpeg)

### 3.     WELCOME PAGE
_________________________________
![enter image description here](https://www.linkpicture.com/q/WhatsApp-Image-2022-02-11-at-16.28.20.jpeg)

### 4.CASH DEPOSIT
__________________________
![enter image description here](https://www.linkpicture.com/q/WhatsApp-Image-2022-02-11-at-16.29.37.jpeg)

### 5.CASH WITHDRAWAL
_______________________
![enter image description here](https://www.linkpicture.com/q/WhatsApp-Image-2022-02-11-at-16.30.48.jpeg)

### 6. REWARD POINTS
______________________________
![enter image description here](https://www.linkpicture.com/q/WhatsApp-Image-2022-02-11-at-16.32.08.jpeg)

### 7. TRANSFER CASH
_____________________________
![enter image description here](https://www.linkpicture.com/q/WhatsApp-Image-2022-02-11-at-16.33.22.jpeg)

### 8. PASSWORD CHANGE
__________________________________
![enter image description here](https://www.linkpicture.com/q/WhatsApp-Image-2022-02-11-at-16.35.16.jpeg)
______________________________________
## Contributors List and Summary

PS NO. |  NAME  |    FEATURES    |
-------|---------|----------------|
99007631| ABISHEK G  | INTERNET BANKING SYSTEM
     

## Challenges Faced and How Was It Overcome

1. Applying FILES concept was quite challenging.


## Learning Resources
1. ADVLEARNINGS .
2. [markdownBasics](https://guides.github.com/features/mastering-markdown/)
3. [github workflow](https://docs.github.com/en/actions/learn-github-action)
## THE CODE OF THIS PROJECT IS LEARNT AND DEVELOPED FROM [code with c website](https://www.codewithc.com/mini-project-in-c-bank-management-system/#google_vignette)
## REFFERED FROM ADVLEARNINGS 
____________________
