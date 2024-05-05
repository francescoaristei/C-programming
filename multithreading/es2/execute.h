# ifndef EXECUTE
# define EXECUTE

using namespace std;

# include <thread>
# include <mutex>
# include <condition_variable>
# include <list>
# include <functional>


class Execute {
    public:
        Execute ();
        ~Execute ();
        // as pushTask()
        void executeAndCallback (function<void ()> task, function<void ()> callback);

    private:
        Execute (const Execute&) = delete;
        Execute operator=(const Execute&) = delete;
        void run ();
        list<function<void ()>> tasks;
        list<function<void ()>> callbacks;
        bool quit;
        mutex m;
        thread t;
        condition_variable cv;
};

# endif