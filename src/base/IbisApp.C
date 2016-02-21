#include "IbisApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<IbisApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

IbisApp::IbisApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  IbisApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  IbisApp::associateSyntax(_syntax, _action_factory);
}

IbisApp::~IbisApp()
{
}

// External entry point for dynamic application loading
extern "C" void IbisApp__registerApps() { IbisApp::registerApps(); }
void
IbisApp::registerApps()
{
  registerApp(IbisApp);
}

// External entry point for dynamic object registration
extern "C" void IbisApp__registerObjects(Factory & factory) { IbisApp::registerObjects(factory); }
void
IbisApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void IbisApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { IbisApp::associateSyntax(syntax, action_factory); }
void
IbisApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
