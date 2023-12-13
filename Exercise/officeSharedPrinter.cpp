//
// Created by jeong on 2023-12-12.
//
#include <iostream>
#include <string>
#include <queue>

class Job {
private:
    int id;
    std::string userName;
    int copy;
public:
    Job() = default;
    ~Job() { }

    Job(int job_id, std::string name, int copy_nums) : id(job_id), userName(name), copy(copy_nums) {
        std::cout << "Create Job {" << id << "}" << "requested by" << userName << std::endl;
        std::cout << "Total copy : " << copy << std::endl;
    }

    Job(const Job &other) : id(other.id), userName(other.userName), copy(other.copy) {
        std::cout << "Create Job {" << id << "}" << "requested by" << userName << std::endl;
        std::cout << "Total copy : " << copy << std::endl;
    }

    friend std::ostream &operator<<(std::ostream &os, const Job &job) {
        return (os << "Print Job[" << job.id << "]" << " requested by " << job.userName << " total papers : " << job.copy
                   << std::endl);
    }

    Job &operator=(const Job &other){
        this->id = other.id;
        this->userName = other.userName;
        this->copy = other.copy;
    }

};

class Printer {
    std::queue<Job> wait;
    int jobId;
public:
    Printer() { jobId = 0; }

    ~Printer() = default;

    void requestJob(std::string user, int copy_nums) {
        wait.push(Job(jobId++, user, copy_nums));
    }

    void performJob() {
        if (wait.size() > 0) {
            std::cout << wait.front();
            wait.pop();
        }
    }
};

int main(){
    Printer printer;

    printer.requestJob("Jeong", 5);
    printer.requestJob("min", 5);

    printer.performJob();
    printer.performJob();
}