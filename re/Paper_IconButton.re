[@bs.module "react-native-paper"]
external reactClass: ReasonReact.reactClass = "IconButton";

[@bs.deriving abstract]
type props = {
  [@bs.optional]
  color: string,
  [@bs.optional]
  size: float,
  [@bs.optional]
  disabled: bool,
  [@bs.optional]
  accessibilityLabel: string,
  [@bs.optional]
  onPress: unit => unit,
  [@bs.optional] [@bs.as "icon"]
  iconAsString: string,
  [@bs.optional] [@bs.as "icon"]
  iconAsRenderFunc: Icon.renderIcon,
  [@bs.optional]
  style: ReactNative.Style.t,
  [@bs.optional]
  theme: Paper_ThemeProvider.appTheme,
};

let make =
    (
      ~icon,
      ~color=?,
      ~size=?,
      ~disabled=?,
      ~accessibilityLabel=?,
      ~onPress=?,
      ~style=?,
      ~theme=?,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      switch (icon) {
      | Icon.Name(name) =>
        props(
          ~color?,
          ~size?,
          ~disabled?,
          ~accessibilityLabel?,
          ~iconAsString=name,
          ~onPress?,
          ~style?,
          ~theme?,
          (),
        )
      | Icon.Element(renderFunc) =>
        props(
          ~color?,
          ~size?,
          ~disabled?,
          ~accessibilityLabel?,
          ~iconAsRenderFunc=renderFunc,
          ~onPress?,
          ~style?,
          ~theme?,
          (),
        )
      },
  );
