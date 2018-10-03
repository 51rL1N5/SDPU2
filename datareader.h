#ifndef DATAREADER_H
#define DATAREADER_H

#include <mraa>
#include <vector>

class DataReader{
  vector<mraa::Aio *> inputs;         // Vector of analog inputs

  vector<double>      outputs;        // Vector of outputs
public:

       DataReader();

  void addInput (mraa::Aio * input);  // Add new inputs and initialize output as -1.0 associated
                                      // with that new input

  void updateData ();                 // Read data from every single input
};


#endif // DATAREADER_H
