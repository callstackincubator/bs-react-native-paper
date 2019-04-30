[@bs.module "react-native-paper"]
external reactClass: ReasonReact.reactClass = "FAB";

[@bs.deriving abstract]
type props = {
  [@bs.optional]
  label: string,
  [@bs.optional]
  small: bool,
  [@bs.optional]
  color: string,
  [@bs.optional]
  disabled: bool,
  [@bs.optional]
  theme: Paper_ThemeProvider.appTheme,
  [@bs.optional]
  style: ReactNative.Style.t,
  [@bs.optional]
  onPress: ReactNative.Event.pressEvent => unit,
  [@bs.optional]
  accessibilityLabel: string,
  [@bs.optional] [@bs.as "icon"]
  iconAsString: string,
  [@bs.optional] [@bs.as "icon"]
  iconAsRenderFunc: Icon.renderIcon,
};

let make =
    (
      ~label=?,
      ~accessibilityLabel=?,
      ~disabled=?,
      ~small=?,
      ~color=?,
      ~theme=?,
      ~icon,
      ~style=?,
      ~onPress=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      switch (icon) {
      | Icon.Name(name) =>
        props(
          ~color?,
          ~iconAsString=name,
          ~style?,
          ~theme?,
          ~onPress?,
          ~accessibilityLabel?,
          ~label?,
          ~disabled?,
          ~small?,
          (),
        )
      | Icon.Element(renderFunc) =>
        props(
          ~color?,
          ~iconAsRenderFunc=renderFunc,
          ~style?,
          ~theme?,
          ~onPress?,
          ~accessibilityLabel?,
          ~label?,
          ~disabled?,
          ~small?,
          (),
        )
      },
    children,
  );

module Group = {
  [@bs.module "react-native-paper"] [@bs.scope "FAB"]
  external reactClass: ReasonReact.reactClass = "Group";

  [@bs.deriving abstract]
  type _fabAction = {
    [@bs.optional] [@bs.as "icon"]
    iconAsString: string,
    [@bs.optional] [@bs.as "icon"]
    iconAsRenderFunc: Icon.renderIcon,
    onPress: unit => unit,
    [@bs.optional]
    label: string,
    [@bs.optional]
    accessibilityLabel: string,
    [@bs.optional]
    color: string,
    [@bs.optional]
    style: ReactNative.Style.t,
  };

  let fabAction =
      (
        ~icon,
        ~onPress,
        ~label=?,
        ~accessibilityLabel=?,
        ~color=?,
        ~style=?,
        _unit,
      ) =>
    switch (icon) {
    | Icon.Name(name) =>
      _fabAction(
        ~iconAsString=name,
        ~onPress,
        ~label?,
        ~accessibilityLabel?,
        ~color?,
        ~style?,
        (),
      )
    | Icon.Element(renderFunc) =>
      _fabAction(
        ~iconAsRenderFunc=renderFunc,
        ~onPress,
        ~label?,
        ~accessibilityLabel?,
        ~color?,
        ~style?,
        (),
      )
    };

  [@bs.deriving abstract]
  type fabState = {
    [@bs.as "open"]
    open_: bool,
  };

  [@bs.deriving abstract]
  type props = {
    onStateChange: fabState => unit,
    actions: array(_fabAction),
    [@bs.as "open"]
    open_: bool,
    [@bs.optional]
    color: string,
    [@bs.optional]
    theme: Paper_ThemeProvider.appTheme,
    [@bs.optional]
    style: ReactNative.Style.t,
    [@bs.optional]
    onPress: ReactNative.Event.pressEvent => unit,
    [@bs.optional]
    accessibilityLabel: string,
    [@bs.optional] [@bs.as "icon"]
    iconAsString: string,
    [@bs.optional] [@bs.as "icon"]
    iconAsRenderFunc: Icon.renderIcon,
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
        switch (icon) {
        | Icon.Name(name) =>
          props(
            ~color?,
            ~open_,
            ~iconAsString=name,
            ~style?,
            ~theme?,
            ~onPress?,
            ~actions,
            ~onStateChange,
            ~accessibilityLabel?,
            (),
          )
        | Icon.Element(renderFunc) =>
          props(
            ~color?,
            ~open_,
            ~iconAsRenderFunc=renderFunc,
            ~style?,
            ~theme?,
            ~onPress?,
            ~actions,
            ~onStateChange,
            ~accessibilityLabel?,
            (),
          )
        },
      children,
    );
};
