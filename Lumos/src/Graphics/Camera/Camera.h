#pragma once
#include "LM.h"

#include "Maths/Maths.h"

namespace Lumos
{
	class LUMOS_EXPORT Camera
	{
	public:
		Camera(float FOV, float Near, float Far, float aspect);
		Camera(float pitch, float yaw, const Maths::Vector3& position, float FOV, float Near, float Far, float aspect);

		virtual ~Camera() {};

		virtual void HandleMouse(float dt, float xpos, float ypos) = 0;
		virtual void HandleKeyboard(float dt) = 0;

		virtual void BuildViewMatrix();
		Maths::Matrix4 BuildViewMatrix(float pitch, float yaw) const;

		Maths::Vector3 GetPosition() const { return m_Position; }
		void SetPosition(const Maths::Vector3& val) { m_Position = val; }

		float GetYaw()   const { return m_Yaw; }
		void SetYaw(float y) { m_Yaw = y; }

		float GetAspectRatio()   const { return m_AspectRatio; }
		void SetAspectRatio(float y) { m_AspectRatio = y; UpdateProjectionMatrix(m_AspectRatio, 1.0f); };

		float GetPitch() const { return m_Pitch; }
		void SetPitch(float p) { m_Pitch = p; }

		void InvertPitch() { m_Pitch = -m_Pitch; }
		void InvertYaw() { m_Yaw = -m_Yaw; }

		virtual void UpdateScroll(float offset, float dt);
		void SetMouseSensitivity(float value) { m_MouseSensitivity = value; }

		inline const Maths::Matrix4& GetProjectionMatrix() const { return m_ProjMatrix; }
		inline void SetProjectionMatrix(const Maths::Matrix4& projectionMatrix) { m_ProjMatrix = projectionMatrix; }
		inline const Maths::Matrix4& GetViewMatrix() const { return m_ViewMatrix; }
		virtual void UpdateProjectionMatrix(float width, float height);

		float GetFar() const { return m_Far; }
		float GetNear() const { return m_Near; }
		float GetFOV() const { return m_Fov; }
		Maths::Vector3 GetUpDirection() const;
		Maths::Vector3 GetRightDirection() const;
		Maths::Vector3 GetForwardDirection() const;

		Maths::Vector3 CalculatePosition() const;
		Maths::Quaternion GetOrientation() const;

		Maths::Vector3 GetVelocity() const { return m_Velocity; }

		virtual float GetScale() const { return 1.0f; }
		virtual void OnImGui();

		friend std::ostream& operator<<(std::ostream& o, const Camera& cam)
		{
			return o << "Camera - Position = (" << cam.GetPosition().GetX() << ", " << cam.GetPosition().GetY() << ", " << cam.GetPosition().GetZ() << ") , Pitch - " << cam.GetPitch() << " , Yaw - " << cam.GetYaw() << std::endl;
		}

	protected:

		float	m_Yaw;
		float	m_Pitch;
		float	m_AspectRatio;
		Maths::Vector3 m_Position;
		Maths::Vector3 m_Velocity;
		Maths::Vector2 m_RotateVelocity;
		float	m_ZoomVelocity;
		float m_CameraSpeed;
		Maths::Vector3 m_FocalPoint;
		float m_Distance;

		Maths::Vector2 m_PreviousCurserPos = Maths::Vector2(0.0f, 0.0f);

		Maths::Matrix4 m_ProjMatrix;
		Maths::Matrix4 m_ViewMatrix;

		float m_Fov, m_Near, m_Far;
		float m_MouseSensitivity = 0.1f;

		float m_ZoomDampeningFactor = 0.00001f;
		float m_DampeningFactor = 0.00001f;
		float m_RotateDampeningFactor = 0.00001f;

		u32 m_ScreenWidth;
		u32 m_ScreenHeight;
	};

}
