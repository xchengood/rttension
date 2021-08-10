//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "RttensionTestApp.h"
#include "RttensionApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
RttensionTestApp::validParams()
{
  InputParameters params = RttensionApp::validParams();
  return params;
}

RttensionTestApp::RttensionTestApp(InputParameters parameters) : MooseApp(parameters)
{
  RttensionTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

RttensionTestApp::~RttensionTestApp() {}

void
RttensionTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  RttensionApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"RttensionTestApp"});
    Registry::registerActionsTo(af, {"RttensionTestApp"});
  }
}

void
RttensionTestApp::registerApps()
{
  registerApp(RttensionApp);
  registerApp(RttensionTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
RttensionTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  RttensionTestApp::registerAll(f, af, s);
}
extern "C" void
RttensionTestApp__registerApps()
{
  RttensionTestApp::registerApps();
}
