#include<iostream>
#include<vector>
using namespace std;

class Section{
    private:
    string title;
    string discription;
    bool status;

    public:
    Section(const string &name,const string& discription):title(name),discription(discription),status(false){}
    string getName() const{
        return title;
    }
    string getDis() const{
        return discription;
    }
    bool completed() const{
        return status;
    }

    void setname(const string& name){
        title=name;
    }
    void setDis(const string &dis){
        discription=dis;
    }
    void mark(){
        status=true;
    }
    void displaytask(){
        cout << title << " (Status: " 
             << (status ? "Completed)" : "Pending)")
             << endl << "   Description: " << discription << endl;
    }
};

class todolist{
    private:
    vector<Section>tasks;

    public:
    void displayMenu()
    {
        cout
            << "\n---------- To-Do List Menu -----------\n";
        cout << "1. Add Task\n";
        cout << "2. Delete Task\n";
        cout << "3. Display Tasks\n";
        cout << "4. Mark Task as Completed\n";
        cout << "5. Exit\n";
        cout << "-----------------------------------------"
                "\n";
    }
    void addTask(){
        string name,discription,duedate;
        cout<<"Enter the title of your Task:";
        cin.ignore();
        getline(cin,name);
        cout<<"Enter the discription: ";
        getline(cin,discription);
        tasks.emplace_back(name,discription);
        cout<<"Task added successfully!!!"<<endl;
    }
    void DeleteTask(){
        if(tasks.empty()){
            cout<<"no task to delete"<<endl;
            return;
        }
        cout << "Tasks:" << endl;
        for (int i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << "Name: "<<tasks[i].getName()<<"Discription is :"<<tasks[i].getDis()
                 << endl;
        }
        cout<<"Enter the place of task that is to be deleted:";
        int taskid;
        cin>>taskid;
        if(taskid>=1&&taskid<=tasks.size()){
            tasks.erase(tasks.begin()+taskid-1);
            cout<<"Task erased succesfully"<<endl;
        }else{
            cout<<"There no task with that position"<<endl;
        }
    }
    void displayTasks(){
         if (tasks.empty()) {
            cout << "No tasks to display!" << endl;
            return;
        }
        cout << "Tasks:" << endl;
        for (int i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". ";
            tasks[i].displaytask();
        }
    }
    void markTaskCompleted(){
        if(tasks.empty()){
            cout<<"no task to delete"<<endl;
            return;
        }
        cout << "Tasks:" << endl;
        for (int i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << "Name: "<<tasks[i].getName()<<"Discription is :"<<tasks[i].getDis() << endl;
        }
        cout<<"Enter the place of task that is to be deleted:";
        int taskid;
        cin>>taskid;
        if(taskid>=1&&taskid<=tasks.size()){
            tasks[taskid-1].mark();
            cout<<"Task marked as completed succesfully"<<endl;
        }else{
            cout<<"Theres no task with that position"<<endl;
        }
    }
    void run()
    {
        int choice;
        do {
            displayMenu();
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                DeleteTask();
                break;
            case 3:
                displayTasks();
                break;
            case 4:
                markTaskCompleted();
                break;
            case 5:
                cout << "Exiting program. Bye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again!" << endl;
            }
        } while (choice != 5);
    }

};
int main(){
    todolist todolist1;
    todolist1.run();
    return 0;
}