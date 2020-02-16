This is a simple C++ sample to demonstrate the generic use case where a user just want to use a base class's vritual function to access a sub-class's function but don't want to know exactly which sub-classes implemented the virtual function.

The sample uses an abstract base class to describe all things about Vehcles. 
The sub-classes, such as Sedan, Truck, SUV, etc. implement the details of their own type respectively.
The caller accesses vehicle through the base class interface(Vehicle) and do not need to know what specific vehicle(such as Sedan, Truck, SUV...) they're dealing with. All that the caller can/need to do is defined by the pure virtual function interface.


Results:
```
I am SUV in VIRGINIA. I have 4 wheels. SUV is for driving over rough terrains. They usually offer all-wheel drive which is beneficial in difficult weathers.
I am Sedan in CALIFORNIA. I have 4 wheels. Sedan is small, lightweight, fuel economic cars for daily driving needs.
I am Truck in TEXAS. I have 4 wheels. Truck is larger, usually for tow and haul, as well as flexible.
```
