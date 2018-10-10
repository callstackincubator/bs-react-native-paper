[@bs.module "react-native-paper"]
external reactClass: ReasonReact.reactClass = "Dialog";

[@bs.deriving abstract]
type props = {
  visible: bool,
  onDismiss: unit => unit,
  [@bs.optional]
  dismissable: bool,
  [@bs.optional]
  theme: Paper_ThemeProvider.appTheme,
  [@bs.optional]
  style: BsReactNative.Style.t,
};

let make =
    (~dismissable=true, ~visible, ~theme=?, ~style=?, ~onDismiss, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=props(~visible, ~onDismiss, ~dismissable, ~theme?, ~style?, ()),
    children,
  );

module Actions = {
  [@bs.module "react-native-paper"] [@bs.scope "Dialog"]
  external reactClass: ReasonReact.reactClass = "Actions";

  [@bs.deriving abstract]
  type props = {
    [@bs.optional]
    style: BsReactNative.Style.t,
  };

  let make = (~style=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=props(~style?, ()),
      children,
    );
};

module Content = {
  [@bs.module "react-native-paper"] [@bs.scope "Dialog"]
  external reactClass: ReasonReact.reactClass = "Content";

  [@bs.deriving abstract]
  type props = {
    [@bs.optional]
    style: BsReactNative.Style.t,
  };

  let make = (~style=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=props(~style?, ()),
      children,
    );
};
module ScrollArea = {
  [@bs.module "react-native-paper"] [@bs.scope "Dialog"]
  external reactClass: ReasonReact.reactClass = "ScrollArea";

  [@bs.deriving abstract]
  type props = {
    [@bs.optional]
    style: BsReactNative.Style.t,
  };

  let make = (~style=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=props(~style?, ()),
      children,
    );
};
module Title = {
  [@bs.module "react-native-paper"] [@bs.scope "Dialog"]
  external reactClass: ReasonReact.reactClass = "Title";

  [@bs.deriving abstract]
  type props = {
    [@bs.optional]
    theme: Paper_ThemeProvider.appTheme,
    [@bs.optional]
    style: BsReactNative.Style.t,
  };

  let make = (~style=?, ~theme=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=props(~style?, ~theme?, ()),
      children,
    );
};
