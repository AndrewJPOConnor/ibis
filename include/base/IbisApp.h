#ifndef IBISAPP_H
#define IBISAPP_H

#include "MooseApp.h"

class IbisApp;

template<>
InputParameters validParams<IbisApp>();

class IbisApp : public MooseApp
{
public:
  IbisApp(InputParameters parameters);
  virtual ~IbisApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* IBISAPP_H */
