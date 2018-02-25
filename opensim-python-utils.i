/* File : opensim-python-utils.i */
%module opensim_pytils

%{
#define SWIG_FILE_WITH_INIT
%}

// %include "pyWrapOpensim.i"

%{
/* Note : always include headers following the inheritance order */

#include <OpenSim/Simulation/Manager/Manager.h>
#include <OpenSim/Simulation/Model/Model.h>
#include "IntegratorInjector.h"

%}

%include "IntegratorInjector.h"

%feature("autodoc","1");
