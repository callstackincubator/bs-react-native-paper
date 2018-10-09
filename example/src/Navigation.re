module Config = {
  type route =
    | Home
    | SnackbarExample
    | SurfaceExample
    | TypographyExample
    | DividerExample
    | SwitchExample
    | RadioButtonExample
    | CheckboxExample
    | ButtonExample
    | ListAccordionExample
    | FABExample;
};

include ReboltNavigation.Navigation.CreateNavigation(Config);
