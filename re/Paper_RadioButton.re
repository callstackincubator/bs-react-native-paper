[@bs.module "react-native-paper"]
external reactClass: ReasonReact.reactClass = "RadioButton";

[@bs.deriving jsConverter]
type status = [
  | [@bs.as "checked"] `checked
  | [@bs.as "unchecked"] `unchecked
];

[@bs.deriving abstract]
type props = {
  value: string,
  [@bs.optional]
  status: string,
  [@bs.optional]
  theme: Paper_ThemeProvider.appTheme,
  [@bs.optional]
  disabled: bool,
  [@bs.optional]
  color: string,
  [@bs.optional]
  onPress: ReactNative.Event.pressEvent => unit,
  [@bs.optional]
  uncheckedColor: string,
};

let make =
    (
      ~value,
      ~status,
      ~theme=?,
      ~disabled=?,
      ~color=?,
      ~onPress=?,
      ~uncheckedColor=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      props(
        ~value,
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
  [@bs.module "react-native-paper"] [@bs.scope "RadioButton"]
  external reactClass: ReasonReact.reactClass = "Android";

  let make =
      (
        ~value,
        ~status,
        ~theme=?,
        ~disabled=?,
        ~color=?,
        ~onPress=?,
        ~uncheckedColor=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        props(
          ~value,
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
  [@bs.module "react-native-paper"] [@bs.scope "RadioButton"]
  external reactClass: ReasonReact.reactClass = "IOS";

  [@bs.deriving jsConverter]
  type status = [
    | [@bs.as "checked"] `checked
    | [@bs.as "unchecked"] `unchecked
  ];

  [@bs.deriving abstract]
  type props = {
    value: string,
    [@bs.optional]
    status: string,
    [@bs.optional]
    theme: Paper_ThemeProvider.appTheme,
    [@bs.optional]
    disabled: bool,
    [@bs.optional]
    color: string,
    [@bs.optional]
    onPress: ReactNative.Event.pressEvent => unit,
  };

  let make =
      (~value, ~status, ~theme=?, ~disabled=?, ~color=?, ~onPress=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        props(
          ~value,
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

module Group = {
  [@bs.module "react-native-paper"] [@bs.scope "RadioButton"]
  external reactClass: ReasonReact.reactClass = "Group";

  [@bs.deriving abstract]
  type props = {
    value: string,
    onValueChange: string => unit,
  };

  let make = (~value, ~onValueChange, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=props(~value, ~onValueChange),
      children,
    );
};
