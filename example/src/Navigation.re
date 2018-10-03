module Config = {
  type route =
    | Home
    | SnackbarExample
    | SurfaceExample;
};

include ReboltNavigation.Navigation.CreateNavigation(Config);
