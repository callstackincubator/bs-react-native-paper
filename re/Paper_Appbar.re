[@bs.module "react-native-paper"]
external reactClass: ReasonReact.reactClass = "Appbar";

[@bs.deriving abstract]
type props = {
  [@bs.optional]
  dark: bool,
  [@bs.optional]
  style: BsReactNative.Style.t,
  [@bs.optional]
  theme: Paper_ThemeProvider.appTheme,
};

let make = (~dark=?, ~theme=?, ~style=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=props(~dark?, ~theme?, ~style?, ()),
    children,
  );

module Content = {
  [@bs.module "react-native-paper"] [@bs.scope "Appbar"]
  external reactClass: ReasonReact.reactClass = "Content";

  [@bs.deriving abstract]
  type props = {
    title: ReasonReact.reactElement,
    [@bs.optional]
    titleStyle: BsReactNative.Style.t,
    [@bs.optional]
    subtitle: ReasonReact.reactElement,
    [@bs.optional]
    subtitleStyle: BsReactNative.Style.t,
    [@bs.optional]
    color: string,
    [@bs.optional]
    style: BsReactNative.Style.t,
    [@bs.optional]
    theme: Paper_ThemeProvider.appTheme,
  };

  let make =
      (
        ~color=?,
        ~title,
        ~titleStyle=?,
        ~subtitle=?,
        ~subtitleStyle=?,
        ~theme=?,
        ~style=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        props(
          ~color?,
          ~title,
          ~titleStyle?,
          ~subtitle?,
          ~subtitleStyle?,
          ~theme?,
          ~style?,
          (),
        ),
      children,
    );
};

module Action = {
  [@bs.module "react-native-paper"] [@bs.scope "Appbar"]
  external reactClass: ReasonReact.reactClass = "Action";

  [@bs.deriving abstract]
  type props = {
    icon: ReasonReact.reactElement,
    [@bs.optional]
    size: int,
    [@bs.optional]
    color: string,
    [@bs.optional]
    disabled: bool,
    [@bs.optional]
    accessibilityLabel: string,
    [@bs.optional]
    style: BsReactNative.Style.t,
    [@bs.optional]
    onPress: unit => unit,
  };

  let make =
      (
        ~color=?,
        ~size=?,
        ~icon,
        ~disabled=?,
        ~accessibilityLabel=?,
        ~onPress=?,
        ~style=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        props(
          ~color?,
          ~size?,
          ~icon,
          ~disabled?,
          ~accessibilityLabel?,
          ~onPress?,
          ~style?,
          (),
        ),
      children,
    );
};

module BackAction = {
  [@bs.module "react-native-paper"] [@bs.scope "Appbar"]
  external reactClass: ReasonReact.reactClass = "BackAction";

  [@bs.deriving abstract]
  type props = {
    [@bs.optional]
    size: int,
    [@bs.optional]
    color: string,
    [@bs.optional]
    disabled: bool,
    [@bs.optional]
    accessibilityLabel: string,
    [@bs.optional]
    style: BsReactNative.Style.t,
    [@bs.optional]
    onPress: unit => unit,
  };

  let make =
      (
        ~color=?,
        ~size=?,
        ~disabled=?,
        ~accessibilityLabel=?,
        ~onPress=?,
        ~style=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        props(
          ~color?,
          ~size?,
          ~disabled?,
          ~accessibilityLabel?,
          ~onPress?,
          ~style?,
          (),
        ),
      children,
    );
};

module Header = {
  [@bs.module "react-native-paper"] [@bs.scope "Appbar"]
  external reactClass: ReasonReact.reactClass = "Header";

  [@bs.deriving abstract]
  type props = {
    [@bs.optional]
    dark: bool,
    [@bs.optional]
    statusBarHeight: int,
    [@bs.optional]
    style: BsReactNative.Style.t,
    [@bs.optional]
    theme: Paper_ThemeProvider.appTheme,
  };

  let make = (~dark=?, ~statusBarHeight=?, ~theme=?, ~style=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=props(~dark?, ~statusBarHeight?, ~theme?, ~style?, ()),
      children,
    );
};
