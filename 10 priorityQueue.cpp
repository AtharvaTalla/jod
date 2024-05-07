#include <queue>
#include <string>
#include <iostream>
using namespace std;
struct Patient {
   string name;
  int priority;
  Patient(const  string& name, int priority) : name(name), priority(priority) {}
};

int main() {
  auto comparePatients = [](const Patient& p1, const Patient& p2) {
    return p1.priority > p2.priority;
  };

   priority_queue<Patient,  vector<Patient>, decltype(comparePatients)> patientQueue(comparePatients);

  int numPatients;
   cout << "Enter the number of patients: ";
   cin >> numPatients;
   cin.ignore(); 

  for (int i = 0; i < numPatients; ++i) {
     string name;
    int priority;
    
     cout << "Enter name of patient " << i+1 << ": ";
     getline( cin, name);
    
     cout << "Enter priority of patient " << i+1 << " (1 for Serious, 2 for Non-serious, 3 for General Checkup): ";
     cin >> priority;
     cin.ignore();

    patientQueue.emplace(name, priority);
  }

   cout << "\nTreating patients:\n";
  while (!patientQueue.empty()) {
    Patient nextPatient = patientQueue.top();
    patientQueue.pop();

     string priorityStr;
    if (nextPatient.priority == 1)
        priorityStr = "Serious";
    else if (nextPatient.priority == 2)
        priorityStr = "Non-serious";
    else
        priorityStr = "General Checkup";
     cout << "Name: " << nextPatient.name << ", Priority: " << priorityStr <<  endl;
  }
  return 0;
}












// ALGORITHM:
// Explanation:

// 1. Data Structures:

// 1. Priority enum for representing patient priorities.
// 2. Patient class to store patient information.
// 3. priority_queue with custom comparison for priority-based ordering.

// 2. Comparison Function:

// 1. comparePatients prioritizes patients based on priority.
// 2. You can add logic for breaking ties based on arrival time or other factors.

// 3. Adding Patients:

// 1. Use push to add patients with their priority and arrival time.

// 4. Serving Patients:

// 1. Use top to access the highest priority patient.
// 2. Use pop to remove the served patient from the queue.

// 5. Output:

// 1. The program prints the served patients in priority order.
