
/**
 * User: Rich
 * Date: 6/22/2015
 * Time: 9:12 AM
 *
 * Strategy Pattern:
 * - A strategy pattern defines a family of algorithms.
 * - Encapsulates each one.
 * - And then makes them interchangeable.
 *
 * In this way we can build loosely coupled applications via polymorphism with the ability to swap out
 * the various algorithms at runtime.
 *
 *
 */
#include <iostream>
#include <cstdio>

using namespace std;


//Encapsulate and make them interchangeable
class Logger {
public:
    virtual void log(string data)=0;
};

// Define a family of algorithms
class LogToFile : public Logger{
public:
    void log(string data)
    {
        printf("Log %s to a file.\n", data.c_str());
    }
};

class LogToDataBase : public Logger{
public:
    void log(string data)
    {
        printf("Log %s to a database.\n", data.c_str());
    }
};

class LogToWebService : public Logger{
public:
    void log(string data)
    {
        printf("Log %s to a web service.\n", data.c_str());
    }
};

// define an App class
class App {
public:
    void log(string data, Logger *logger = nullptr)
    {
        logger = logger ?: new LogToFile;

        logger->log(data);
    }
};

int main()
{
    // create app instance
    App *app = new App;

    // pop. Logs for looping example.
    Logger *Logs[] = {new LogToFile, new LogToDataBase, new LogToWebService, nullptr};

    for(Logger *log : Logs)
    {
        app->log("Some DATA", log);
    }
    app->log("Some DATA");


    return 0;
}
