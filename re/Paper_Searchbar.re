[@bs.module "react-native-paper"]
external reactClass: ReasonReact.reactClass = "Searchbar";

[@bs.deriving abstract]
type props = {
  [@bs.optional]
  placeholder: string,
  [@bs.optional]
  value: string,
  [@bs.optional] [@bs.as "icon"]
  iconAsString: string,
  [@bs.optional] [@bs.as "icon"]
  iconAsRenderFunc: Icon.renderIcon,
  [@bs.optional]
  theme: Paper_ThemeProvider.appTheme,
  [@bs.optional]
  style: ReactNative.Style.t,
  onChangeText: string => unit,
  [@bs.optional]
  onIconPress: ReactNative.Event.pressEvent => unit,
};

let make =
    (
      ~placeholder=?,
      ~value=?,
      ~icon=?,
      ~theme=?,
      ~style=?,
      ~onChangeText,
      ~onIconPress=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      switch (icon) {
      | Some(Icon.Name(name)) =>
        props(
          ~placeholder?,
          ~value?,
          ~iconAsString=name,
          ~theme?,
          ~style?,
          ~onChangeText,
          ~onIconPress?,
          (),
        )
      | Some(Icon.Element(renderFunc)) =>
        props(
          ~placeholder?,
          ~value?,
          ~iconAsRenderFunc=renderFunc,
          ~theme?,
          ~style?,
          ~onChangeText,
          ~onIconPress?,
          (),
        )
      | None =>
        props(
          ~placeholder?,
          ~value?,
          ~theme?,
          ~style?,
          ~onChangeText,
          ~onIconPress?,
          (),
        )
      },
    children,
  );
