# Integrator Injector for OpenSim 3.3
Since the Python bindings for OmpenSim 3.3 export methods to the simulation Integrator but don't export simbody integrators, I implemented a quick way to Inject a new integrator into a Manager without binding Simbody's Integrator in Python.

This will be hopefully obsolete as soon as a stable OpenSim 4.0 will be available, as bindings for many part of Simbody are in the works.