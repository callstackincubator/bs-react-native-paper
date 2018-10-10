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
    | ListSectionExample
    | FABExample
    | DialogExample;
};

include ReboltNavigation.Navigation.CreateNavigation(Config);
