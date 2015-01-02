leetcode solutions
========
Note: CMake and google test library are required

#### Install GTest on Mac/Linux:

(1) Download gtest [gtest-1.7.0.zip](https://code.google.com/p/googletest/downloads/list) and unzip 

(2) Build gtest:
{% highlight bash %}
cd gtest-1.7.0

mkdir build

cd build

cmake ..

make
{% endhighlight %}

(3) Install gtest library
{% highlight bash %}
sudo cp -r ../include/gtest /usr/local/include/

sudo cp lib*.a /usr/local/lib
{% endhighlight %}

#### Compile using CMake
{% highlight bash %}
mkdir build

cd build

cmake ..
    
make
{% endhighlight %}
