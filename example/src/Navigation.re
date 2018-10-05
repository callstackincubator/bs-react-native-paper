module Config = {
  type route =
    | Home
    | SnackbarExample
    | SurfaceExample
    | TypographyExample
<<<<<<< Updated upstream
    | DividerExample;
=======
    | DividerExample
    | SwitchExample
    | RadioButtonExample
    | CheckboxExample
    | ButtonExample;
>>>>>>> Stashed changes
};

include ReboltNavigation.Navigation.CreateNavigation(Config);