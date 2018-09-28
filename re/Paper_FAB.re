[@bs.module "react-native-paper"]
external reactClass: ReasonReact.reactClass = "FAB";

let make =
    (
      ~label: option(string)=?,
      ~accessibilityLabel: option(string)=?,
      ~disabled: bool=false,
      ~small: bool=false,
      ~color: option(string)=?,
      ~theme: option(Paper_ThemeProvider.appTheme)=?,
      ~icon: ReasonReact.reactElement,
      ~style: option(BsReactNative.Style.t)=?,
      ~onPress: option(BsReactNative.RNEvent.NativeEvent.t => unit)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Null_undefined.{
        "label": label,
        "accessibilityLabel": accessibilityLabel,
        "disabled": disabled,
        "small": small,
        "color": fromOption(color),
        "icon": icon,
        "onPress": fromOption(onPress),
        "style": fromOption(style),
        "theme": fromOption(theme),
      },
    children,
  );

module Group = {
  [@bs.module "react-native-paper"] [@bs.scope "FAB"]
  external reactClass: ReasonReact.reactClass = "Group";

  [@bs.deriving abstract]
  type fabAction = {
    icon: string,
    onPress: unit => unit,
    [@bs.optional]
    label: string,
    [@bs.optional]
    accessibilityLabel: string,
    [@bs.optional]
    color: string,
    [@bs.optional]
    style: BsReactNative.Style.t,
  };

  [@bs.deriving abstract]
  type fabState = {
    [@bs.as "open"]
    open_: bool,
  };

  [@bs.deriving abstract]
  type props = {
    icon: ReasonReact.reactElement,
    onStateChange: fabState => unit,
    actions: array(fabAction),
    [@bs.as "open"]
    open_: bool,
    [@bs.optional]
    color: string,
    [@bs.optional]
    theme: Paper_ThemeProvider.appTheme,
    [@bs.optional]
    style: BsReactNative.Style.t,
    [@bs.optional]
    onPress: BsReactNative.RNEvent.NativeEvent.t => unit,
    [@bs.optional]
    accessibilityLabel: string,
  };

  let make =
      (
        ~color=?,
        ~open_,
        ~theme=?,
        ~icon,
        ~style=?,
        ~onPress=?,
        ~onStateChange,
        ~accessibilityLabel=?,
        ~actions,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        props(
          ~color?,
          ~open_,
          ~icon,
          ~style?,
          ~theme?,
          ~onPress?,
          ~actions,
          ~onStateChange,
          ~accessibilityLabel?,
          (),
        ),
      children,
    );
};
