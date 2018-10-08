module Config = {
  type route =
    | Home
    | SnackbarExample
    | SurfaceExample
    | TypographyExample
    | DividerExample
    | ButtonExample;
};

include ReboltNavigation.Navigation.CreateNavigation(Config);
