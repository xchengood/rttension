#include "RttensionApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
RttensionApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy material output, i.e., output properties on INITIAL as well as TIMESTEP_END
  params.set<bool>("use_legacy_material_output") = false;

  return params;
}

RttensionApp::RttensionApp(InputParameters parameters) : MooseApp(parameters)
{
  RttensionApp::registerAll(_factory, _action_factory, _syntax);
}

RttensionApp::~RttensionApp() {}

void
RttensionApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"RttensionApp"});
  Registry::registerActionsTo(af, {"RttensionApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
RttensionApp::registerApps()
{
  registerApp(RttensionApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
RttensionApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  RttensionApp::registerAll(f, af, s);
}
extern "C" void
RttensionApp__registerApps()
{
  RttensionApp::registerApps();
}
