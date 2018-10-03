module Config = {
  type route =
    | Home
    | SnackbarExample;
};

include ReboltNavigation.Navigation.CreateNavigation(Config);
