#include <OpenSim/Simulation/Manager/Manager.h>
#include <OpenSim/Simulation/Model/Model.h>

class IntegratorInjector
{
private:
    SimTK::Integrator* integrator;

public:
    IntegratorInjector(OpenSim::Manager& manager, OpenSim::Model& model)
		: integrator(NULL)
    {
        integrator = new SimTK::SemiExplicitEuler2Integrator(model.getMultibodySystem());
        integrator->setAccuracy(0.001);
#if OPENSIM_MAJOR_VERSION == 4
		manager.setIntegrator(*integrator);
#elif OPENSIM_MAJOR_VERSION == 3
        manager.setIntegrator(integrator);
#endif
    }

	~IntegratorInjector()
	{
		if (integrator != NULL)
			delete integrator;
		integrator = NULL;
	}
};
