module Config = {
  type route =
    | Home
    | SnackbarExample
    | SurfaceExample
    | TypographyExample
    | DividerExample;
};

include ReboltNavigation.Navigation.CreateNavigation(Config);
