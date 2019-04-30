[@bs.module "react-native-paper"]
external make:
  (
    ~dark: bool=?,
    ~style: ReactNative.Style.t=?,
    ~theme: Paper_ThemeProvider.appTheme=?,
    ~children: React.element=?
  ) =>
  React.element =
  "Appbar";

module Content = {
  [@bs.module "react-native-paper"] [@bs.scope "Appbar"] [@react.component]
  external make:
    (
      ~title: React.element=?,
      ~titleStyle: ReactNative.Style.t=?,
      ~subtitle: React.element=?,
      ~subtitleStyle: ReactNative.Style.t=?,
      ~color: string=?,
      ~style: ReactNative.Style.t=?,
      ~theme: Paper_ThemeProvider.appTheme=?,
      ~children: React.element=?
    ) =>
    React.element =
    "Content";
};

module Action = {
  [@bs.module "react-native-paper"] [@bs.scope "Appbar"] [@react.component]
  external make:
    (
      ~icon: 'a=?,
      ~size: int=?,
      ~color: string=?,
      ~disabled: bool=?,
      ~accessibilityLabel: string=?,
      ~style: ReactNative.Style.t=?,
      ~onPress: unit => unit=?,
      ~children: React.element=?
    ) =>
    React.element =
    "Action";
};

module BackAction = {
  [@bs.module "react-native-paper"] [@bs.scope "Appbar"] [@react.component]
  external make:
    (
      ~size: int=?,
      ~color: string=?,
      ~disabled: bool=?,
      ~accessibilityLabel: string=?,
      ~style: ReactNative.Style.t=?,
      ~onPress: unit => unit=?,
      ~children: React.element=?
    ) =>
    React.element =
    "BackAction";
};

module Header = {
  [@bs.module "react-native-paper"] [@bs.scope "Appbar"] [@react.component]
  external make:
    (
      ~dark: bool=?,
      ~statusBarHeight: int=?,
      ~style: ReactNative.Style.t=?,
      ~theme: Paper_ThemeProvider.appTheme=?,
      ~children: React.element=?
    ) =>
    React.element =
    "Header";
};
