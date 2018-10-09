type jsIconProps = {
  .
  "color": string,
  "size": float,
};

type iconProps = {
  color: string,
  size: float,
};

type renderIcon = jsIconProps => ReasonReact.reactElement;

let renderIcon =
    (reRenderIcon: iconProps => ReasonReact.reactElement): renderIcon =>
  (jsIconProps: jsIconProps) =>
    reRenderIcon({color: jsIconProps##color, size: jsIconProps##size});

module Icon = {
  [@bs.module "react-native-paper"] [@bs.scope "List"]
  external reactClass: ReasonReact.reactClass = "Icon";

  [@bs.deriving abstract]
  type props = {
    color: string,
    icon: renderIcon,
    [@bs.optional]
    style: BsReactNative.Style.t,
  };

  let make = (~color, ~icon, ~style=?) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=props(~color, ~icon, ~style?, ()),
    );
};

module Accordion = {
  [@bs.module "react-native-paper"] [@bs.scope "List"]
  external reactClass: ReasonReact.reactClass = "Accordion";

  [@bs.deriving abstract]
  type props = {
    title: string,
    [@bs.optional]
    description: string,
    [@bs.optional]
    left: renderIcon,
    [@bs.optional]
    theme: Paper_ThemeProvider.appTheme,
    [@bs.optional]
    style: BsReactNative.Style.t,
  };

  let make = (~title, ~description=?, ~left=?, ~theme=?, ~style=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=props(~title, ~description?, ~left?, ~theme?, ~style?, ()),
      children,
    );
};

module Item = {
  [@bs.module "react-native-paper"] [@bs.scope "List"]
  external listItem: ReasonReact.reactClass = "Item";

  [@bs.deriving abstract]
  type props = {
    title: string,
    [@bs.optional]
    description: string,
    [@bs.optional]
    left: renderIcon,
    [@bs.optional]
    right: renderIcon,
    [@bs.optional]
    onPress: BsReactNative.RNEvent.NativeEvent.t => unit,
    [@bs.optional]
    theme: Paper_ThemeProvider.appTheme,
    [@bs.optional]
    style: BsReactNative.Style.t,
  };

  let make =
      (
        ~title,
        ~description=?,
        ~left=?,
        ~right=?,
        ~onPress=?,
        ~theme=?,
        ~style=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=listItem,
      ~props=
        props(
          ~title,
          ~description?,
          ~left?,
          ~right?,
          ~onPress?,
          ~theme?,
          ~style?,
          (),
        ),
      children,
    );
};

module Section = {
  [@bs.module "react-native-paper"] [@bs.scope "List"]
  external listSection: ReasonReact.reactClass = "Section";

  [@bs.deriving abstract]
  type props = {
    [@bs.optional]
    title: string,
    [@bs.optional]
    theme: Paper_ThemeProvider.appTheme,
    [@bs.optional]
    style: BsReactNative.Style.t,
  };

  let make = (~title=?, ~theme=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=listSection,
      ~props=props(~title?, ~theme?, ()),
      children,
    );
};
