module Config = {
  type route =
    | Home
    | SnackbarExample
    | SurfaceExample
    | TypographyExample;
};

include ReboltNavigation.Navigation.CreateNavigation(Config);
