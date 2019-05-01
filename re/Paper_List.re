type jsIconProps = {. "color": string};

type iconProps = {color: string};

type renderIcon = jsIconProps => ReasonReact.reactElement;

let renderIcon =
    (reRenderIcon: iconProps => ReasonReact.reactElement): renderIcon =>
  (jsIconProps: jsIconProps) => reRenderIcon({color: jsIconProps##color});

module Icon = {
  [@bs.module "react-native-paper"] [@bs.scope "List"]
  external reactClass: ReasonReact.reactClass = "Icon";

  [@bs.deriving abstract]
  type props = {
    color: string,
    [@bs.optional] [@bs.as "icon"]
    iconAsString: string,
    [@bs.optional] [@bs.as "icon"]
    iconAsRenderFunc: Icon.renderIcon,
    [@bs.optional]
    style: ReactNative.Style.t,
  };

  let make = (~color, ~icon, ~style=?) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        switch (icon) {
        | Icon.Name(name) => props(~color, ~iconAsString=name, ~style?, ())
        | Icon.Element(renderFunc) =>
          props(~color, ~iconAsRenderFunc=renderFunc, ~style?, ())
        },
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
    style: ReactNative.Style.t,
  };

  let make = (~title, ~description=?, ~left=?, ~theme=?, ~style=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=props(~title, ~description?, ~left?, ~theme?, ~style?, ()),
      children,
    );
};

module Item = {
  [@bs.module "react-native-paper"] [@bs.scope "List"] [@react.component]
  external make:
    (
      ~title: string,
      ~description: string=?,
      ~left: renderIcon=?,
      ~right: renderIcon=?,
      ~onPress: ReactNative.Event.pressEvent => unit=?,
      ~theme: Paper_ThemeProvider.appTheme=?,
      ~style: ReactNative.Style.t=?
    ) =>
    React.element =
    "Item";
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
    style: ReactNative.Style.t,
  };

  let make = (~title=?, ~theme=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=listSection,
      ~props=props(~title?, ~theme?, ()),
      children,
    );
};
