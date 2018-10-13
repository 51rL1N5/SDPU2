#include "datareader.h"
#include <mraa>

DataReader::DataReader()
{

}

void DataReader::addInput(mraa::Aio * input)
{
  inputs.push_back(input);
  outputs.push_back(-1.0)
}

void DataReader::updateData ()
{
  for (int i = 0; i < outputs.size(); i++)
  {
    outputs[i] = inputs[i]->readFloat();
  }
}
