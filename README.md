# PyBed

## Calling Python from C++
Call Python from C++ with the utmost ease with a couple of lines!
<br />
First instantiate an instance of PyBed in the python-notated location of your script (so ```./your_script.py``` would be ```your_script```):
```c++
PyBed pybed = PyBed::InitWithScript("your_script"); // would be found at your_script.py in the working directory
```
Great now you have an instance of the python embedder. It's as easy as pie calling functions now, all you have to do is call ```Invoke``` casted to the desired return type with the parameter being the function name like so:
```c++
int day = pybed.Invoke<int>("get_day_of_the_month");
```
Where in your python script you would have the following:
```python
from datetime import date

def get_day_of_the_month():
    return date.today().day
```
And if you wish to call a function in your Python module with arguments, you can! Like so:
```c++
std::string concatenated = pybed.InvokeWithArgs<std::string>("concat", str1, str2);
```
Where the equivalent in your Python script would look something like:
```python
def concat(str1, str2):
    return str1 + str2
```

This is all just scratching the service as the possibilities are endless and the benefit of avoiding compilation of native code where appropriate is priceless.

This project is wrapped on pybind11 and further abtracts the binding process facilitating interop for developers.

## Calling C++ from Python
I have not worked on calling C++ from Python yet, as it stands this library currently only supports calling Python from C++ however I plan to implement the other way around too sometime in the future.

## Building
To build run the following:
```bash
cmake .
make
```

The resultant ```libPyBed.a``` static library file will be generated to which along with the include file ```pybed.h``` can be linked and compiled against any native project.

## Tests

To run tests build the lightweight test suite by calling the following in the ```test``` directory:
```bash
make && ./test.out
```

After building one just has to call ```./test.out``` to run tests again

To rebuild and rerun tests run:
```bash
make clean && make && ./test.out
```