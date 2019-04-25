[@bs.module "react-native-paper"]
external reactClass: ReasonReact.reactClass = "Checkbox";

[@bs.deriving jsConverter]
type status = [
  | [@bs.as "checked"] `checked
  | [@bs.as "unchecked"] `unchecked
  | [@bs.as "indeterminate"] `indeterminate
];

[@bs.deriving abstract]
type props = {
  status: string,
  [@bs.optional]
  onPress: ReactNative.Event.pressEvent => unit,
  [@bs.optional]
  theme: Paper_ThemeProvider.appTheme,
  [@bs.optional]
  disabled: bool,
  [@bs.optional]
  color: string,
  [@bs.optional]
  uncheckedColor: string,
};

let make =
    (
      ~status,
      ~theme=?,
      ~disabled=?,
      ~color=?,
      ~uncheckedColor=?,
      ~onPress=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      props(
        ~status=statusToJs(status),
        ~theme?,
        ~disabled?,
        ~color?,
        ~onPress?,
        ~uncheckedColor?,
        (),
      ),
    children,
  );

module Android = {
  [@bs.module "react-native-paper"] [@bs.scope "Checkbox"]
  external reactClass: ReasonReact.reactClass = "Android";

  let make =
      (
        ~status,
        ~theme=?,
        ~disabled=?,
        ~color=?,
        ~uncheckedColor=?,
        ~onPress=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        props(
          ~status=statusToJs(status),
          ~theme?,
          ~disabled?,
          ~color?,
          ~onPress?,
          ~uncheckedColor?,
          (),
        ),
      children,
    );
};

module IOS = {
  [@bs.module "react-native-paper"] [@bs.scope "Checkbox"]
  external reactClass: ReasonReact.reactClass = "IOS";

  [@bs.deriving abstract]
  type props = {
    status: string,
    [@bs.optional]
    onPress: ReactNative.Event.pressEvent => unit,
    [@bs.optional]
    theme: Paper_ThemeProvider.appTheme,
    [@bs.optional]
    disabled: bool,
    [@bs.optional]
    color: string,
  };

  let make = (~status, ~theme=?, ~disabled=?, ~color=?, ~onPress=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        props(
          ~status=statusToJs(status),
          ~theme?,
          ~disabled?,
          ~color?,
          ~onPress?,
          (),
        ),
      children,
    );
};
