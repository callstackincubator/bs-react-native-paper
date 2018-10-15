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
    | DialogExample
    | CardExample
    | AppbarExample
    | IconButtonExample
    | ProgressBarExample
    | SearchbarExample
    | TouchableRippleExample
    | ChipExample
    | TextInputExample
    | BottomNavigationExample;
};

include ReboltNavigation.Navigation.CreateNavigation(Config);
