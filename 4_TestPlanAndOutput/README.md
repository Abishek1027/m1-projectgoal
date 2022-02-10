# TEST PLAN:
### TABLE : High Level Test Plan 
___ 
|Test Id  | Description |Exp I/P  |Exp O/P  |Act O/P  |Test Type  |
|--|--|--|--|--|--|
| HLR1 |Registration of new account|Account number:123456 Phone no:8072334574 Password: 12345|User Registration Successfull|User Registration Successfull|Requirement based|
|HLR2|Existing user|Phone no:8072334574 Password:12345|Welcome 123456|Welcome 123456|Requirement based|
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


