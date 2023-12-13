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
    Job(int job_id, std::string name, int copy_nums) : id(job_id), userName(name), copy(copy_nums) {
        std::cout << "Create Job {" << id << "}" << "requested by" << userName << std::endl;
        std::cout << "Total copy : " << copy;
    }

    Job(const Job &other) : id(other.id), userName(other.userName), copy(other.copy) {
        std::cout << "Create Job {" << id << "}" << "requested by" << userName << std::endl;
        std::cout << "Total copy : " << copy;
    }



    Job() = default;
};

class Printer {
    std::queue<Job> queue;
    int jobId;

    Printer() { jobId = 0; }

    void requestJob(std::string user, int copy_nums) {
        queue.emplace(jobId++, user, copy_nums);
    }

    Job performJob() {
        Job item;
        if (queue.size() > 0) {
            item = queue.front();
            queue.pop();
            return item;
        }

    }

};